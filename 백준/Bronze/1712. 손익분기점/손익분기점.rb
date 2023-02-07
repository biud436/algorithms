a, b, c = gets.split(" ").map(&:to_i)

if b >= c
  puts -1 
else
  puts a / (c - b) + 1
end