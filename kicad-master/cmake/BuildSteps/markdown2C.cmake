# CMake script file to process a text file by wrapping every line in double quotes.
# Input file must not abuse quotes, staying with single quotes is probably best.
# note also empty lines cannot be stripped: they have a meaning (separator) in markdown
# so we use file( READ ... ) to read the full file content, including empty lines

file( READ ${inputFile} buffer )

file( WRITE ${outputFile} "// Do not edit this file, it is autogenerated by CMake from the .md file\n" )

#Remark: strings can contain semicolon. a semicolon is a separation in cmake.
#so, to avoid stripping semicolon in variables we have to quote them

# Replace each "\" char by "\\". the \ is found in .md files
# to prepend some chars that are usually control chars
STRING( REPLACE "\\" "\\\\" linea "${buffer}" )

# Replace each " char by \"
STRING( REPLACE "\"" "\\\"" linem "${linea}" )

# Replace each EOL char by "\n" + " + EOL
STRING( REPLACE "\n" "\\n\"\n\"" buff_m "${linem}" )

# create the full string compatible "C":
# _HKI( "<md string>"\n
# to make it translatable. We use here the marker _HKI because
# the translation will be explicitely called in Kicad code
# Write the buffer between quotes
file( APPEND ${outputFile} "_HKI( \"" "${buff_m}" "\" );\n" )
