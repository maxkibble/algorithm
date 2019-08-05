for ((i = 1; i <= 100; i++)); do
  echo "case $i"
  ./gen $i > input
  ./a < input > a.out
  ./brute < input > brute.out
  diff -w a.out brute.out || break
done
