/**************************************************/
/* 1. CREACIÓN DE TABLAS                     */
/* Estructuras necesarias para la aplicación */
/**************************************************/

-- Tabla Dietas
-- NOTA: Se usan VARCHAR para FechaInicio y otros campos, reflejando el uso de String^ en el código C++/CLI.
CREATE TABLE Dietas (
    IdDieta INT PRIMARY KEY,
    IdAnimal INT NOT NULL,
    FechaInicio VARCHAR(100), -- Podría ser de tipo DATE si solo se almacena la fecha.
    Alimentos VARCHAR(500),
    Frecuencia VARCHAR(100)
    -- Asumiendo que Animales existe, se podría añadir una clave foránea:
    -- FOREIGN KEY (IdAnimal) REFERENCES Animales(IdAnimal)
);

/**************************************************/
/* 2. COMANDOS DML (Data Manipulation Language)*/
/* Operaciones de CRUD y Actualización       */
/**************************************************/

-- 2.1. CONSULTAR TODAS LAS DIETAS (Implementado en el bloque try-catch de carga)
-- Función: GestorNutricionalController::obtenerTodasDietas()
SELECT 
    IdDieta, 
    IdAnimal, 
    FechaInicio, 
    Alimentos, 
    Frecuencia 
FROM 
    Dietas;


-- 2.2. REGISTRAR DIETA (INSERT)
-- Función: GestorNutricionalController::registrarDieta(Dieta^ dieta)
-- El código en C++/CLI genera un comando como el siguiente:
INSERT INTO Dietas (IdDieta, IdAnimal, FechaInicio, Alimentos, Frecuencia) 
VALUES(
    /* {dieta->Id} */ 101, 
    /* '{dieta->IdAnimal}' */ 5, 
    /* '{dieta->FechaInicio}' */ '2025-11-25', 
    /* '{dieta->Alimentos}' */ 'Pasto; Heno; Agua', 
    /* '{dieta->Frecuencia}' */ 'Diario'
);


-- 2.3. MODIFICAR DIETA (UPDATE)
-- Función: GestorNutricionalController::modificarDieta(...)
-- El código en C++/CLI genera un comando como el siguiente:
UPDATE Dietas SET 
    IdAnimal = /* '{idAnimal}' */ 6, 
    FechaInicio = /* '{fechaInicio}' */ '2025-11-26', 
    Alimentos = /* '{alimentos}' */ 'Concentrado A; Agua', 
    Frecuencia = /* '{frecuencia}' */ 'Dos veces al día' 
WHERE 
    IdDieta = /* {id} */ 101;


-- 2.4. ELIMINAR DIETA (DELETE)
-- Función: GestorNutricionalController::eliminarDieta(int id)
-- El código en C++/CLI genera un comando como el siguiente:
DELETE FROM Dietas 
WHERE 
    IdDieta = /* {id} */ 101;


INSERT INTO Dietas (IdDieta, IdAnimal, FechaInicio, Alimentos, Frecuencia)
VALUES
    (201, 1, '2025-11-20', 'Pasto, Heno de alfalfa, Bloque salino', 'Diario, suministro constante'),
    (202, 2, '2025-11-25', 'Concentrado para cabras (2kg), Vainas de leguminosas, Agua fresca', '3 veces al día'),
    (203, 3, '2025-11-25', 'Maíz, Salvado de trigo, Suplemento proteico. Ración controlada.', '2 veces al día, 1.5kg por porción'),
    (204, 1, '2025-12-01', 'Heno de pasto, Silaje de maíz, Probióticos', 'Diario (mañana y tarde)');

SELECT * FROM Dietas;