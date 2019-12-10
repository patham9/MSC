Str=`ls src/*.c | xargs`
echo $Str
echo "Compilation started: Unused code will be printed and removed from the binary:"
avr-gcc -D_POSIX_C_SOURCE=199506L -mmcu=avr6 -pedantic -std=c99 -g3 -O3 -Wall -Wextra -Wformat-security $Str -lm -oMSC
echo "Done."

