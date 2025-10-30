class CityRescue
  DIRECTIONS = [[1,0], [-1,0], [0,1], [0,-1]]

  def initialize(grid)
    @grid = grid
    @rows = grid.size
    @cols = grid[0].size
    @fire_time = Array.new(@rows) { Array.new(@cols, Float::INFINITY) }
    @rescue_points = []
    @safe_points = []
    parse_grid
  end

  def parse_grid
    @rows.times do |r|
      @cols.times do |c|
        case @grid[r][c]
        when 'F' then @fire_time[r][c] = 0
        when 'R' then @rescue_points << [r, c]
        when 'S' then @safe_points << [r, c]
        end
      end
    end
  end

  def spread_fire
    queue = []
    @rows.times do |r|
      @cols.times do |c|
        queue << [r, c] if @grid[r][c] == 'F'
      end
    end

    until queue.empty?
      r, c = queue.shift
      DIRECTIONS.each do |dr, dc|
        nr, nc = r + dr, c + dc
        next unless valid?(nr, nc)
        if @fire_time[nr][nc] == Float::INFINITY
          @fire_time[nr][nc] = @fire_time[r][c] + 1
          queue << [nr, nc]
        end
      end
    end
  end

  def find_shortest_safe_path
    spread_fire
    queue = []
    visited = Array.new(@rows) { Array.new(@cols, false) }

    @rescue_points.each do |r, c|
      queue << [r, c, 0]
      visited[r][c] = true
    end

    until queue.empty?
      r, c, t = queue.shift
      return t if @safe_points.include?([r, c])
      DIRECTIONS.each do |dr, dc|
        nr, nc = r + dr, c + dc
        next unless valid?(nr, nc)
        next if visited[nr][nc]
        next if @fire_time[nr][nc] <= t + 1
        visited[nr][nc] = true
        queue << [nr, nc, t + 1]
      end
    end

    nil
  end

  private

  def valid?(r, c)
    r.between?(0, @rows - 1) && c.between?(0, @cols - 1) && @grid[r][c] != '#'
  end
end

# Example Usage
grid = [
  ['R', '.', '.', 'F', '.'],
  ['.', 'F', '.', '.', '.'],
  ['.', '.', '.', 'F', '.'],
  ['.', '.', '.', '.', 'S'],
  ['F', '.', '.', '.', '.']
]

solver = CityRescue.new(grid)
result = solver.find_shortest_safe_path
if result
  puts "Shortest safe path length: #{result}"
else
  puts "No safe path exists."
end
