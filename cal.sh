#Shell program to replicate a calculator
echo "Enter two numbers:"
read a
read b
c=1
while (($c != 5))
do
echo "Enter your choice:"
read c
case $c in
1)
echo "$((a + b))"
;;
2)
echo "$((a - b))"
;;
3)
echo "$((a * b))"
;;
4)
echo "$((a / b))"
;;
5)
echo "Exiting..."
;;
*)
echo "Invalid Input"
;;
esac
done