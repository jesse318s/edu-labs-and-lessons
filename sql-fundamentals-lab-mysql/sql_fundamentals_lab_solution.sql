-- =========================================================
-- Coffee Shop SQL Fundamentals Lab - SOLUTION
-- =========================================================

-- ---------------------------------------------------------
-- Schema Definition
-- ---------------------------------------------------------
CREATE TABLE Customers (
    CustomerID INT NOT NULL,
    FirstName VARCHAR(100) NOT NULL,
    LastName VARCHAR(100) NOT NULL,
    Email VARCHAR(100),
    PRIMARY KEY (CustomerID)
);

CREATE TABLE Products (
    ProductID INT NOT NULL,
    ProductName VARCHAR(100) NOT NULL,
    PRIMARY KEY (ProductID)
);

CREATE TABLE Orders (
    OrderID INT NOT NULL,
    CustomerID INT NOT NULL,
    ProductID INT NOT NULL,
    Quantity INT NOT NULL,
    OrderDate TIMESTAMP NOT NULL,
    PRIMARY KEY (OrderID),
    FOREIGN KEY (CustomerID) REFERENCES Customers(CustomerID),
    FOREIGN KEY (ProductID) REFERENCES Products(ProductID)
);

-- ---------------------------------------------------------
-- Seed Data
-- ---------------------------------------------------------
INSERT INTO Customers (CustomerID, FirstName, LastName, Email)
VALUES
(1, 'John', 'Doe', 'johndoe@example.com'),
(2, 'Jane', 'Doe', 'janedoe@example.com');

INSERT INTO Products (ProductID, ProductName)
VALUES
(1, 'large coffee'),
(2, 'small coffee');

INSERT INTO Orders (OrderID, CustomerID, ProductID, Quantity, OrderDate)
VALUES
(1, 1, 1, 2, '2026-09-03 12:00:00'),
(2, 1, 2, 1, '2026-09-03 12:01:00'),
(3, 2, 1, 1, '2026-09-03 12:02:00');

-- =========================================================
-- Task Solutions
-- =========================================================

-- Task 1: SELECT statement - Get all customers
SELECT *
FROM Customers;

-- Task 2: WHERE clause - Get a specific customer
SELECT *
FROM Customers
WHERE CustomerID = 1;

-- Task 3: JOIN statement - Get all orders with customer details
SELECT Orders.OrderID, Customers.FirstName, Customers.LastName, Orders.Quantity, Orders.OrderDate
FROM Orders
JOIN Customers ON Orders.CustomerID = Customers.CustomerID;

-- Task 4: GROUP BY clause - Get count of customer orders grouped by product
SELECT COUNT(CustomerID) AS OrderCount
FROM Orders
GROUP BY ProductID;

-- Task 5: HAVING clause - Get products ordered more than once
SELECT Products.ProductName, COUNT(Orders.OrderID) AS NumberOfOrders
FROM Orders
JOIN Products ON Orders.ProductID = Products.ProductID
GROUP BY Products.ProductName
HAVING COUNT(Orders.OrderID) > 1;

-- Task 6: ORDER BY statement - Get all orders sorted by OrderDate descending
SELECT *
FROM Orders
ORDER BY OrderDate DESC;

-- Task 7: CASE statement - Categorize order sizes based on quantity
SELECT OrderID, CustomerID, ProductID, Quantity, OrderDate,
    CASE
        WHEN Quantity <= 1 THEN 'Small'
        WHEN Quantity <= 3 THEN 'Medium'
        ELSE 'Large'
    END AS OrderSize
FROM Orders;

-- Task 8: Subquery - Get orders with quantity greater than the average order quantity
SELECT *
FROM Orders
WHERE Quantity > (
    SELECT AVG(Quantity)
    FROM Orders
);

-- Task 9: UPDATE statement - Update a customer email
UPDATE Customers
SET Email = 'newemail@example.com'
WHERE CustomerID = 1;

-- Task 10: DELETE statement - Delete an order
DELETE FROM Orders
WHERE OrderID = 1;

-- =========================================================
-- Verification Queries
-- =========================================================

-- Verify email update on Customer 1
SELECT CustomerID, FirstName, LastName, Email
FROM Customers
WHERE CustomerID = 1;

-- Verify removal of Order 1
SELECT *
FROM Orders
WHERE OrderID = 1;
