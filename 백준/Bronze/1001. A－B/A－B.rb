c = gets
f = c.split(" ").collect! {|i| i.to_i }
p f.reduce(:-)