n, l = gets.split.map(&:to_i)

def find_sequence(n, l)
  while l <= 100
    total = l * (l - 1) / 2
    if (n - total) % l == 0
      a = (n - total) / l
      if a >= 0
        return (0...l).map { |i| a + i }.join(' ')
      end
    end
    l += 1
  end
  return -1
end

puts find_sequence(n, l)
