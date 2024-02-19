/*
 * This program source code file is part of KiCad, a free EDA CAD application.
 *
 * Copyright (C) 2023 KiCad Developers, see AUTHORS.txt for contributors.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, you may find one here:
 * http://www.gnu.org/licenses/old-licenses/gpl-2.0.html
 * or you may search the http://www.gnu.org website for the version 2 license,
 * or you may write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
 */

#include <board.h>
#include <kiid.h>
#include <pcb_reference_image.h>
#include <pcbnew_utils/board_file_utils.h>
#include <pcbnew_utils/board_test_utils.h>
#include <qa_utils/wx_utils/unit_test_utils.h>
#include <settings/settings_manager.h>

namespace
{

struct REFERENCE_IMAGE_LOAD_TEST_FIXTURE
{
    REFERENCE_IMAGE_LOAD_TEST_FIXTURE() {}
};


struct REFERENCE_IMAGE_LOAD_TEST_CASE
{
    // Which one to look at in the file
    KIID     m_imageUuid;
    // Expected values
    bool     m_expectedLocked;
    VECTOR2I m_expectedPos;
    double   m_expectedScale;
    // This should also check correct image decoding, as it won't work otherwise
    VECTOR2I m_expectedPixelSize;
};


struct REFERENCE_IMAGE_LOAD_BOARD_TEST_CASE
{
    // The board to load
    wxString m_boardFileRelativePath;
    // List of images to check
    std::vector<REFERENCE_IMAGE_LOAD_TEST_CASE> m_imageCases;
};

} // namespace

BOOST_FIXTURE_TEST_CASE( ReferenceImageLoading, REFERENCE_IMAGE_LOAD_TEST_FIXTURE )
{
    const std::vector<REFERENCE_IMAGE_LOAD_BOARD_TEST_CASE> testCases{
        {
                "reference_images_load_save",
                {
                        // From top to bottom in the board file
                        {
                                "7dde345e-020a-4fdd-af77-588b452be5e0",
                                false,
                                { 100, 46 },
                                1.0,
                                { 64, 64 },
                        },
                        {
                                "e4fd52dd-1d89-4c43-b621-aebfc9788d5c",
                                true,
                                { 100, 65 },
                                1.0,
                                { 64, 64 },
                        },
                        {
                                "d402397e-bce0-4cae-a398-b5aeef397e87",
                                false,
                                { 100, 90 },
                                2.0,
                                { 64, 64 }, // It's the same size, but scaled
                        },
                },
        },
    };

    for( const REFERENCE_IMAGE_LOAD_BOARD_TEST_CASE& testCase : testCases )
    {
        const auto doBoardTest = [&]( const BOARD& aBoard )
        {
            for( const REFERENCE_IMAGE_LOAD_TEST_CASE& imageTestCase : testCase.m_imageCases )
            {
                BOOST_TEST_MESSAGE(
                        "Checking for image with UUID: " << imageTestCase.m_imageUuid.AsString() );

                const auto& image =
                        static_cast<PCB_REFERENCE_IMAGE&>( KI_TEST::RequireBoardItemWithTypeAndId(
                                aBoard, PCB_REFERENCE_IMAGE_T, imageTestCase.m_imageUuid ) );

                BOOST_CHECK_EQUAL( image.IsLocked(), imageTestCase.m_expectedLocked );
                BOOST_CHECK_EQUAL( image.GetPosition(), imageTestCase.m_expectedPos * 1000000 );
                BOOST_CHECK_CLOSE( image.GetImageScale(), imageTestCase.m_expectedScale, 1e-6 );

                const BITMAP_BASE* bitmap = image.GetImage();

                BOOST_REQUIRE( bitmap );

                BOOST_TEST_MESSAGE( "Got underlying image" );

                BOOST_CHECK_EQUAL( bitmap->GetSizePixels(), imageTestCase.m_expectedPixelSize );
            }
        };

        KI_TEST::LoadAndTestBoardFile( testCase.m_boardFileRelativePath, true, doBoardTest );
    }
}