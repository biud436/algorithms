n = gets.to_i
arr = gets.split.map(&:to_i)
sorted_arr = arr.dup.sort {|a, b| a - b}
dp = []

def com(target, idx)
    if not target.include?(idx)
        target << idx
    else
        com(target, idx + 1)    
    end
end

arr.each do |i|
    idx = sorted_arr.index(i)

    com(dp, idx)
end

puts dp.join(" ")