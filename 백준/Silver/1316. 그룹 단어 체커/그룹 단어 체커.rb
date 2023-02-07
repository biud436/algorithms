n = gets.to_i
c = 0

def valid(s)
  v = {}
  last = ''
  s.each do |e|
    id = e.downcase
    if last != id
      if v.keys.include?(id)
        return false
      else
        v[id] = true
      end
    end
    last = e
  end
  
  return true
end

for i in (0...n)
  s = gets.split("")
  c += 1 if valid(s)
end

puts c