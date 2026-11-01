-- =========================================================
-- Coffee Shop SQL Fundamentals Lab
-- =========================================================
-- Complete the task below each comment block using the schema
-- and seed data provided. Write your query directly beneath
-- each task's instructions.
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
-- Tasks
-- =========================================================

-- Task 1: SELECT statement
-- Retrieve every column and record from the Customers table.


-- Task 2: WHERE clause
-- Select all customer attributes where CustomerID equals 1.


-- Task 3: JOIN statement
-- Combine Orders and Customers on CustomerID to output OrderID,
-- customer FirstName, LastName, Quantity, and OrderDate.


-- Task 4: GROUP BY clause
-- Group orders by ProductID and count the number of customer
-- records associated with each product.


-- Task 5: HAVING clause
-- Join Orders and Products, group by ProductName, count orders,
-- and keep only products ordered more than once.


-- Task 6: ORDER BY statement
-- Select all order records sorted descending by OrderDate.


-- Task 7: CASE statement
-- Categorize each order's size based on Quantity:
--   'Small'  when Quantity <= 1
--   'Medium' when Quantity <= 3
--   'Large'  when Quantity > 3


-- Task 8: Subquery
-- Select all orders where Quantity is strictly greater than the
-- average Quantity across all orders (computed with a nested
-- AVG() subquery).


-- Task 9: UPDATE statement
-- Update the Email for CustomerID = 1 to 'newemail@example.com'.


-- Task 10: DELETE statement
-- Delete the order record where OrderID = 1.

