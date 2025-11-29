-- Script to create the 'Insumos' table if it does not exist
IF OBJECT_ID('dbo.Insumos', 'U') IS NULL
BEGIN
    CREATE TABLE Insumos (
        id      INT IDENTITY(1,1) NOT NULL PRIMARY KEY,
        nombre  NVARCHAR(100)     NOT NULL,
        tipo    NVARCHAR(50)      NOT NULL,
        unidad  NVARCHAR(50)      NOT NULL
    );
END
GO
-- Script to insert initial data into the 'Insumos' table
INSERT INTO Insumos (nombre, tipo, unidad) VALUES
('Maíz', 'Grano', 'kg'),
('Trigo', 'Grano', 'kg'),
('Melaza', 'Líquido', 'litros'),
('Aceite vegetal', 'Líquido', 'litros'),
('Salvado de trigo', 'Fibra', 'kg'),
('Premix vitamínico', 'Suplemento', 'kg'),
('Carbonato de calcio', 'Mineral', 'kg'),
('Suero lácteo', 'Líquido', 'litros'),
('Heno seco', 'Forraje', 'kg'),
('Antiparasitario', 'Medicamento', 'pastillas'),
('Harina de maíz', 'Harina', 'kg');
GO
-- End of migration script for 'Insumos' table


-- Script to create the 'Almacenes' table if it does not exist
IF OBJECT_ID('dbo.Almacenes', 'U') IS NULL
BEGIN
    CREATE TABLE Almacenes (
        id      INT IDENTITY(1,1) NOT NULL PRIMARY KEY,
        nombre  NVARCHAR(100)     NOT NULL,
        ubicacion NVARCHAR(200)   NOT NULL
    );
END
GO
-- Script to insert initial data into the 'Almacenes' table
INSERT INTO Almacenes (nombre, ubicacion) VALUES
('Principal', 'Norte'),
('Secundario1', 'Sur'),
('Secundario2', 'Este'),
('Secundario3', 'Oeste'),
('Secundario4', 'SurEste');
GO
-- End of migration script for 'Almacenes' table


-- Script to create the 'StockInsumos' table if it does not exist
IF OBJECT_ID('dbo.StockInsumos', 'U') IS NULL
BEGIN
    CREATE TABLE StockInsumos (
        id            INT IDENTITY(1,1) NOT NULL PRIMARY KEY,
        idInsumo     INT           NOT NULL FOREIGN KEY REFERENCES Insumos(id),
        idAlmacen    INT           NOT NULL FOREIGN KEY REFERENCES Almacenes(id),
        stock        FLOAT         NOT NULL,
        limiteBajo   FLOAT         NOT NULL,
        limiteAlto   FLOAT         NOT NULL
    );
END
GO
-- Script to insert initial data into the 'StockInsumos' table
INSERT INTO StockInsumos (idInsumo, idAlmacen, stock, limiteBajo, limiteAlto) VALUES
(1, 1, 10, 10, 40),
(1, 2, 40, 5, 50),
(1, 3, 3, 5, 30),
(1, 4, 50, 10, 50),
(1, 5, 0, 10, 50),
(2, 1, 10, 1, 35),
(2, 2, 3, 3, 20),
(3, 1, 0, 5, 10),
(4, 1, 3, 5, 10),
(5, 1, 7, 5, 10),
(6, 1, 10, 5, 10);
GO
-- End of migration script for 'StockInsumos' table
