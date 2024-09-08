function love.load()
    startTime = os.clock()
    result = 0.0
    local iterations = 100000  -- Puedes ajustar este valor

    -- Realizamos cálculos simples para probar la CPU
    for i = 1, iterations do
        result = result + math.sin(i) * math.cos(i)
    end

    endTime = os.clock()
    elapsedTime = endTime - startTime
    print("Tiempo de prueba de CPU: " .. elapsedTime .. " segundos")
end

function love.draw()
    love.graphics.print("Resultado: " .. result, 400, 300)
    love.graphics.print("Tiempo de prueba: " .. (endTime - startTime) .. " segundos", 400, 350)
end
