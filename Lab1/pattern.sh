/*
 
Program: Write shell script using for loop to print the following patterns on screen.


*/

echo "Name: Kalyani Nayak"
echo "RegNo: 1947228"

echo "Printing Pattern"
for ((i=1; i<=5; i++))
do
for ((j=1; j<=$i; j++))
do
echo -n "$i"
done
echo ""
done