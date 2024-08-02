def dfs(x, y, w, h, graph)
    return false if (x <= -1) or (x >= w) or y <= -1 or y >= h
    
    graph[x] ||= []
    if graph[x][y] == 1
        graph[x][y] = 0
        dfs(x - 1, y, w, h, graph)
        dfs(x, y - 1, w, h, graph)
        dfs(x + 1, y, w, h, graph)
        dfs(x, y + 1, w, h, graph)
        return true
    end

    return false
end

n = gets.to_i
n.times do 
    w, h, count = gets.split.map(&:to_i)

    graph = Array.new(w) { Array.new(h, 0) }
    count.times do 
        x, y = gets.split.map(&:to_i)
        graph[x][y] = 1
    end

    result = 0
    for i in (0...w)
        for j in (0...h)
            if dfs(i, j, w, h, graph) == true
                result += 1
            end
        end
    end

    puts result
end

