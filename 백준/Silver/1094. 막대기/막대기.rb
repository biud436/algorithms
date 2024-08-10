x = gets.to_i

count = 0

while (x > 0)
    if ( x % 2 == 1 )
        count += 1
    end

    x /= 2
end

puts count