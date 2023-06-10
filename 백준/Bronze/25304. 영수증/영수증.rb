total = gets.chomp.to_i
n = gets.chomp.to_i

for i in 1..n
  a, b = gets.chomp.split(" ").map(&:to_i)
  c = a * b
  
  total -= c

end

if total == 0
    puts "Yes"
else
    puts "No"
end