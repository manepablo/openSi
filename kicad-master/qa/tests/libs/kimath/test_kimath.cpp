/*
 * This program source code file is part of KiCad, a free EDA CAD application.
 *
 * Copyright (C) 2020 KiCad Developers, see AUTHORS.TXT for contributors.
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

/**
 * Test suite for KiCad math code.
 */

#include <qa_utils/wx_utils/unit_test_utils.h>

// Code under test
#include <trigo.h>
#include <geometry/shape_arc.h>


/*
CircleCenterFrom3Points calculate the center of a circle defined by 3 points
It is similar to CalcArcCenter( const VECTOR2D& aStart, const VECTOR2D& aMid, const VECTOR2D& aEnd )
but it was needed to debug CalcArcCenter, so I keep it available for other issues in CalcArcCenter

The perpendicular bisector of the segment between two points is the
set of all points equidistant from both.  So if you take the
perpendicular bisector of (x1,y1) and (x2,y2) and the perpendicular
bisector of the segment from (x2,y2) to (x3,y3) and find the
intersection of those lines, that point will be the center.

To find the equation of the perpendicular bisector of (x1,y1) to (x2,y2),
you know that it passes through the midpoint of the segment:
((x1+x2)/2,(y1+y2)/2), and if the slope of the line
connecting (x1,y1) to (x2,y2) is m, the slope of the perpendicular
bisector is -1/m.  Work out the equations for the two lines, find
their intersection, and bingo!  You've got the coordinates of the center.

An error should occur if the three points lie on a line, and you'll
need special code to check for the case where one of the slopes is zero.

see https://web.archive.org/web/20171223103555/http://mathforum.org/library/drmath/view/54323.html
*/
static bool Ref0CircleCenterFrom3Points( const VECTOR2D& p1, const VECTOR2D& p2, const VECTOR2D& p3,
                                        VECTOR2D* aCenter )
{
    // Move coordinate origin to p2, to simplify calculations
    VECTOR2D b = p1 - p2;
    VECTOR2D d = p3 - p2;
    double   bc = ( b.x * b.x + b.y * b.y ) / 2.0;
    double   cd = ( -d.x * d.x - d.y * d.y ) / 2.0;
    double   det = -b.x * d.y + d.x * b.y;

    if( fabs( det ) < 1.0e-6 ) // arbitrary limit to avoid divide by 0
        return false;

    det = 1 / det;
    aCenter->x = ( -bc * d.y - cd * b.y ) * det;
    aCenter->y = ( b.x * cd + d.x * bc ) * det;
    *aCenter += p2;

    return true;
}


// Based on https://paulbourke.net/geometry/circlesphere/
// Uses the Y'b equation too, depending on slope values
static const VECTOR2D Ref1CalcArcCenter( const VECTOR2D& aStart, const VECTOR2D& aMid, const VECTOR2D& aEnd )
{
    VECTOR2D center;
    double   yDelta_21 = aMid.y - aStart.y;
    double   xDelta_21 = aMid.x - aStart.x;
    double   yDelta_32 = aEnd.y - aMid.y;
    double   xDelta_32 = aEnd.x - aMid.x;

    // This is a special case for aMid as the half-way point when aSlope = 0 and bSlope = inf
    // or the other way around.  In that case, the center lies in a straight line between
    // aStart and aEnd
    if( ( ( xDelta_21 == 0.0 ) && ( yDelta_32 == 0.0 ) )
        || ( ( yDelta_21 == 0.0 ) && ( xDelta_32 == 0.0 ) ) )
    {
        center.x = ( aStart.x + aEnd.x ) / 2.0;
        center.y = ( aStart.y + aEnd.y ) / 2.0;
        return center;
    }

    // Prevent div=0 errors
    /*if( xDelta_21 == 0.0 )
        xDelta_21 = std::numeric_limits<double>::epsilon();

    if( xDelta_32 == 0.0 )
        xDelta_32 = -std::numeric_limits<double>::epsilon();*/

    double aSlope = yDelta_21 / xDelta_21;
    double bSlope = yDelta_32 / xDelta_32;

    if( aSlope == bSlope )
    {
        if( aStart == aEnd )
        {
            // This is a special case for a 360 degrees arc.  In this case, the center is halfway between
            // the midpoint and either newEnd point
            center.x = ( aStart.x + aMid.x ) / 2.0;
            center.y = ( aStart.y + aMid.y ) / 2.0;
            return center;
        }
        else
        {
            // If the points are colinear, the center is at infinity, so offset
            // the slope by a minimal amount
            // Warning: This will induce a small error in the center location
            /*aSlope += std::numeric_limits<double>::epsilon();
            bSlope -= std::numeric_limits<double>::epsilon();*/
        }
    }

    center.x = ( aSlope * bSlope * ( aStart.y - aEnd.y ) + bSlope * ( aStart.x + aMid.x )
                 - aSlope * ( aMid.x + aEnd.x ) )
               / ( 2 * ( bSlope - aSlope ) );

    if( std::abs( aSlope ) > std::abs( bSlope ) )
    {
        center.y = ( ( ( aStart.x + aMid.x ) / 2.0 - center.x ) / aSlope
                     + ( aStart.y + aMid.y ) / 2.0 );
    }
    else
    {
        center.y =
                ( ( ( aMid.x + aEnd.x ) / 2.0 - center.x ) / bSlope + ( aMid.y + aEnd.y ) / 2.0 );
    }

    return center;
}


struct TEST_CALC_ARC_CENTER_CASE
{
    VECTOR2I istart;
    VECTOR2I imid;
    VECTOR2I iend;
};


/**
 * Declare the test suite
 */
BOOST_AUTO_TEST_SUITE( KiMath )


BOOST_AUTO_TEST_CASE( TestCalcArcCenter3Pts )
{
    // Order: start, mid, end
    std::vector<TEST_CALC_ARC_CENTER_CASE> calc_center_cases = {
        //{ { 183000000, 89000000 }, { 185333332, 89000000 }, { 185333333, 91333333 } } // Fails currently
    };

    const double tolerance = 1.0;

    // Check random points (fails currently)
    /*for( int i = 0; i < 100; i++ )
    {
        TEST_CALC_ARC_CENTER_CASE cas;

        cas.istart.x = rand();
        cas.istart.y = rand();

        cas.imid.x = rand();
        cas.imid.y = rand();

        cas.iend.x = rand();
        cas.iend.y = rand();

        calc_center_cases.push_back( cas );
    }*/

    for( const TEST_CALC_ARC_CENTER_CASE& entry : calc_center_cases )
    {
        wxString msg;

        VECTOR2D start( entry.istart );
        VECTOR2D mid( entry.imid );
        VECTOR2D end( entry.iend );

        VECTOR2D calcCenter = CalcArcCenter( start, mid, end );

        double crs = ( calcCenter - start ).EuclideanNorm();
        double crm = ( calcCenter - mid ).EuclideanNorm();
        double cre = ( calcCenter - end ).EuclideanNorm();

        double cavg = ( crs + crm + cre ) / 3.0;

        if( std::abs( crs - cavg ) > tolerance || std::abs( crm - cavg ) > tolerance
            || std::abs( cre - cavg ) > tolerance )
        {
            msg << "CalcArcCenter failed.";

            msg << "\nstart: " << entry.istart.Format();
            msg << "\nmid: " << entry.imid.Format();
            msg << "\nend: " << entry.iend.Format();

            {
                msg << "\nCalculated center: " << wxString::Format( "%.15f", calcCenter.x ) << ", "
                    << wxString::Format( "%.15f", calcCenter.y );

                msg << "\n  Avg radius: " << wxString::Format( "%.15f", cavg );
                msg << "\nStart radius: " << wxString::Format( "%.15f", crs );
                msg << "\n  Mid radius: " << wxString::Format( "%.15f", crm );
                msg << "\n  End radius: " << wxString::Format( "%.15f", cre );
                msg << "\n";

                // Check mid/end points using the calculated center (like SHAPE_ARC)
                EDA_ANGLE angStart( start - calcCenter );
                EDA_ANGLE angMid( mid - calcCenter );
                EDA_ANGLE angEnd( end - calcCenter );

                EDA_ANGLE angCenter = angEnd - angStart;

                VECTOR2D newMid = start;
                VECTOR2D newEnd = start;

                RotatePoint( newMid, calcCenter, -angCenter / 2.0 );
                RotatePoint( newEnd, calcCenter, -angCenter );

                msg << "\nNew mid: " << wxString::Format( "%.15f", newMid.x ) << ", "
                    << wxString::Format( "%.15f", newMid.y );

                msg << "\nNew end: " << wxString::Format( "%.15f", newEnd.x ) << ", "
                    << wxString::Format( "%.15f", newEnd.y );
                msg << "\n";

                double endsDist = ( newEnd - end ).EuclideanNorm();

                msg << "\nNew end is off by " << wxString::Format( "%.15f", endsDist );
                msg << "\n";
            }

            {
                VECTOR2D ref0Center;
                Ref0CircleCenterFrom3Points( start, mid, end, &ref0Center );

                double r0_rs = ( ref0Center - start ).EuclideanNorm();
                double r0_rm = ( ref0Center - mid ).EuclideanNorm();
                double r0_rre = ( ref0Center - end ).EuclideanNorm();

                double r0_ravg = ( r0_rs + r0_rm + r0_rre ) / 3.0;

                msg << "\nReference0 center: " << wxString::Format( "%.15f", ref0Center.x ) << ", "
                    << wxString::Format( "%.15f", ref0Center.y );

                msg << "\nRef0   Avg radius: " << wxString::Format( "%.15f", r0_ravg );
                msg << "\nRef0 Start radius: " << wxString::Format( "%.15f", r0_rs );
                msg << "\nRef0   Mid radius: " << wxString::Format( "%.15f", r0_rm );
                msg << "\nRef0   End radius: " << wxString::Format( "%.15f", r0_rre );
                msg << "\n";
            }

            {
                VECTOR2D ref1Center = Ref1CalcArcCenter( start, mid, end );

                double r1_rs = ( ref1Center - start ).EuclideanNorm();
                double r1_rm = ( ref1Center - mid ).EuclideanNorm();
                double r1_rre = ( ref1Center - end ).EuclideanNorm();

                double r1_ravg = ( r1_rs + r1_rm + r1_rre ) / 3.0;

                msg << "\nReference1 center: " << wxString::Format( "%.15f", ref1Center.x ) << ", "
                    << wxString::Format( "%.15f", ref1Center.y );

                msg << "\nRef1   Avg radius: " << wxString::Format( "%.15f", r1_ravg );
                msg << "\nRef1 Start radius: " << wxString::Format( "%.15f", r1_rs );
                msg << "\nRef1   Mid radius: " << wxString::Format( "%.15f", r1_rm );
                msg << "\nRef1   End radius: " << wxString::Format( "%.15f", r1_rre );
                msg << "\n";
            }


            BOOST_CHECK_MESSAGE( false, msg );
        }
    }
}


BOOST_AUTO_TEST_CASE( TestInterceptsPositiveX )
{
    BOOST_CHECK( !InterceptsPositiveX( 10.0, 20.0 ) );
    BOOST_CHECK( !InterceptsPositiveX( 10.0, 120.0 ) );
    BOOST_CHECK( !InterceptsPositiveX( 10.0, 220.0 ) );
    BOOST_CHECK( !InterceptsPositiveX( 10.0, 320.0 ) );
    BOOST_CHECK( InterceptsPositiveX( 20.0, 10.0 ) );
    BOOST_CHECK( InterceptsPositiveX( 345.0, 15.0 ) );
}


BOOST_AUTO_TEST_CASE( TestInterceptsNegativeX )
{
    BOOST_CHECK( !InterceptsNegativeX( 10.0, 20.0 ) );
    BOOST_CHECK( !InterceptsNegativeX( 10.0, 120.0 ) );
    BOOST_CHECK( InterceptsNegativeX( 10.0, 220.0 ) );
    BOOST_CHECK( InterceptsNegativeX( 10.0, 320.0 ) );
    BOOST_CHECK( InterceptsNegativeX( 20.0, 10.0 ) );
    BOOST_CHECK( !InterceptsNegativeX( 345.0, 15.0 ) );
    BOOST_CHECK( InterceptsNegativeX( 145.0, 225.0 ) );
}


BOOST_AUTO_TEST_SUITE_END()
