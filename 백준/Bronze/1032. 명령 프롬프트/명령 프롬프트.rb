n = gets.chomp.to_i

pattern = nil
n.times do |k|

    target = gets.chomp
    pattern = target if pattern.nil?

    for i in (0..pattern.size)
        if target[i] != pattern[i]
            pattern[i] = '?'
        end
    end
end

puts pattern