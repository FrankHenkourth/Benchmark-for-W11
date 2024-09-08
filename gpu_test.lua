local points = {}
local numPoints = 100000  -- Número de puntos a dibujar
local startTime, endTime, elapsedTime

function love.load()
    -- Generar puntos alberro
    for i = 1, numPoints do
        local x = love.math.random(0, love.graphics.getWidth())
        local y = love.math.random(0, love.graphics.getHeight())
        table.insert(points, {x = x, y = y})
    end
    startTime = os.clock()
end

function love.update(dt)
    --
end

function love.draw()
    local drawStartTime = os.clock()
    
    for _, point in ipairs(points) do
        love.graphics.points(point.x, point.y)
    end

    endTime = os.clock()
    elapsedTime = endTime - drawStartTime
    love.graphics.print("Puntos dibujados: " .. numPoints, 10, 10)
    love.graphics.print("Tiempo de dibujado: " .. string.format("%.4f", elapsedTime) .. " segundos", 10, 30)
end
