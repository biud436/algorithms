def get_distance(x1, y1, x2, y2)
    return Math.sqrt((x1 - x2) ** 2 + (y1 - y2) ** 2)
end

def get_intersection(x1, y1, r1, x2, y2, r2)
    # 두 원의 중심 사이의 거리
    d = get_distance(x1, y1, x2, y2)

    # 두 원이 완전히 일치하는 경우,
    if r1 == r2 and d == 0
        return -1
    # 외접, 내접 인가?
    elsif r1 + r2 == d or d == (r1 - r2).abs
        return 1
    # 두 원이 만나지 않는 경우,
    elsif r1 + r2 < d or d < (r1 - r2).abs
        return 0
    # 두 원이 두 점에서 만나는 경우,
    else
        return 2
    end
    
end

i = gets.chomp.to_i

i.times do
    x1, y1, r1, x2, y2, r2 = gets.chomp.split(" ").map(&:to_i)
    puts get_intersection(x1, y1, r1, x2, y2, r2)
end