#Shell program to check if a year is a leap year or not
echo "Enter a year"
read year
if [ $((year%4)) == 0 ]
then 
echo "Leap Year"
else
echo "Not a Leap Year"
fi