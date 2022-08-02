#Shell program to check if a number is even or odd
echo "Enter the number:"
read a
if [ $((a%2)) == 0 ]
then
echo "Even"
else
echo "Odd"
fi