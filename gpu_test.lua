function love.load()
    startTime = os.clock()
    result = 0.0

    -- Realizamos cálculos simples para probar la GPU
    for i = 1, 100000 do
        result = result + math.sin(i) * math.cos(i)
    end

    endTime = os.clock()
    elapsedTime = endTime - startTime
    print("Tiempo de prueba de GPU: " .. elapsedTime .. " segundos")
end

function love.draw()
    love.graphics.print("Resultado: " .. result, 400, 300)
end
