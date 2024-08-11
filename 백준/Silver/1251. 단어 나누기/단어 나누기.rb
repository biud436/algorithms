word = gets.chomp
words = []

(1...word.length).each do |i|
  (i+1...word.length).each do |j|
    a = word[0...i].reverse
    b = word[i...j].reverse
    c = word[j..-1].reverse
    words.push (a + b + c)
  end
end

puts words.sort[0]
