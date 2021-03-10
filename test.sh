
gcc -Wall -Werror -Wextra get_next_line.c main.c -o get_next_line
./get_next_line < test.txt > yours_.res
cat -e yours_.res > yours.res
cat -e < test.txt > original.res
diff -y --suppress-common-line original.res yours.res
rm -rf original.res yours_.res yours.res get_next_line