n = gets.to_i
result = []

n.times do
    line = gets.chomp
    result << line
end

result = result.sort { |a, b| a.length <=> b.length }
cnt = n

for i in (0...n)
    for j in (i+1...n)
        if result[j][0...result[i].length] == result[i]
            cnt -= 1
            break
        end
    end
end

puts cnt