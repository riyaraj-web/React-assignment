INSERT INTO Product VALUES (1, 'Apple iPhone 14', 'Electronics', 79999.00, 20);
INSERT INTO Product VALUES (2, 'Samsung Galaxy S22', 'Electronics', 69999.00, 25);
INSERT INTO Product VALUES (3, 'Sony Headphones', 'Accessories', 1999.00, 100);
INSERT INTO Product VALUES (4, 'HP Laptop', 'Computers', 55999.00, 15);
INSERT INTO Product VALUES (5, 'Dell Mouse', 'Accessories', 499.00, 200);
INSERT INTO Product VALUES (6, 'Canon Camera', 'Electronics', 45999.00, 10);
INSERT INTO Product VALUES (7, 'Apple Watch', 'Wearables', 30999.00, 30);
INSERT INTO Product VALUES (8, 'Logitech Keyboard', 'Accessories', 1299.00, 150);
INSERT INTO Product VALUES (9, 'Samsung TV', 'Electronics', 55999.00, 5);
INSERT INTO Product VALUES (10, 'Mi Band', 'Wearables', 1999.00, 80);

SELECT * FROM Product

--1
SELECT * FROM Product
WHERE ProductName LIKE 'Apple%';

--2
SELECT *  Product
WHERE ProductName LIKE '%Watch';

--3
SELECT * FROM Product
WHERE ProductName LIKE '%Samsung%';

--4
SELECT * FROM Product
WHERE Category='Electronics' OR Category='Computers';

--5
SELECT * FROM Product
WHERE ProductID =1 OR ProductID =3 OR ProductID =5;

--6
SELECT * FROM Product
WHERE Price>=1000 AND Price<=20000;

--7
SELECT * FROM Product
WHERE Quantity>=10 AND Quantity<=50;

--8
SELECT * FROM Product
WHERE Category='Electronics' AND Price<5000;

--9
SELECT * FROM Product
WHERE Quantity>50 AND Price<5000;

--10
SELECT * FROM Product
WHERE Quantity<20 OR Price>5000;

--11
SELECT * FROM Product
WHERE Category='Accessories' OR Category='Wearables';

--12
SELECT * FROM Product
WHERE NOT Category='Electronics';

--13
SELECT * FROM Product
WHERE Price>=1000 AND Price<=20000;

--14
SELECT * FROM Product
ORDER BY Price ASC;

--15
SELECT * FROM Product
ORDER BY Quantity DESC;

--16
SELECT * FROM Product
ORDER BY Category, ProductName;

--17
UPDATE Product
SET Price = 599
WHERE ProductName = 'Dell Mouse';

--18
UPDATE Product
SET Quantity = Quantity + 20
WHERE ProductName = 'Mi Band';

--19
UPDATE Product
SET Price = Price + 2500
WHERE Category='Wearables';

--20
UPDATE Product
SET Quantity = Quantity -5
WHERE Category = 'Electronics';

-21
