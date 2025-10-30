CREATE TABLE Customer (
 CustomerID INT PRIMARY KEY,
 FirstName VARCHAR(50),
 LastName VARCHAR(50),
 City VARCHAR(50),
 Age INT,
 Email VARCHAR(100)
);

INSERT INTO Customer VALUES
(1, 'John', 'Doe', 'New York', 28, 'john.doe@example.com'),
(2, 'Jane', 'Smith', 'Los Angeles', 34, 'jane.smith@gmail.com'),
(3, 'Alice', 'Johnson', 'Chicago', 22, 'alicej@yahoo.com'),
(4, 'Bob', 'Williams', 'Houston', 45, 'bob_w@outlook.com'),
(5, 'Charlie', 'Brown', 'Phoenix', 31, 'charlie.b@example.com'),
(6, 'David', 'Lee', 'Philadelphia', 29, 'davidlee@gmail.com'),
(7, 'Eve', 'Clark', 'San Diego', 37, 'eve.clark@live.com'),
(8, 'Frank', 'Moore', 'Dallas', 40, 'fmoore@yahoo.com'),
(9, 'Grace', 'Taylor', 'San Jose', 25, 'gracet@gmail.com'),
(10, 'Henry', 'Martin', 'Austin', 33, 'henrym@gmail.com');

--1
SELECT * FROM Customer
WHERE Age>30 AND City='Phoenix';

--2
SELECT * FROM Customer
WHERE Age<30 OR City='New York';

--3
SELECT * FROM Customer
WHERE NOT City='Chicago';

--4
SELECT * FROM Customer
WHERE Age>25 AND NOT City='Dallas';

--5
SELECT * FROM Customer
WHERE City='Los Angeles' OR City='San Diego';

--6
SELECT * FROM Customer
WHERE NOT City='New York' AND AGE<35;

--7
SELECT * FROM Customer
WHERE FirstName LIKE 'J%';

--8
SELECT  * FROM Customer
WHERE LastName LIKE '%n';

--9
SELECT * FROM Customer
WHERE Email LIKE '%gmail%';

--10
SELECT * FROM Customer
WHERE FirstName LIKE '%a%';

--11
SELECT * FROM Customer
WHERE Email LIKE '%.com';

--12
SELECT * FROM Customer
WHERE LENGTH(LastName)=5;

--13
SELECT * FROM Customer
ORDER BY Age ASC;

--14
SELECT * FROM Customer
ORDER BY FirstName DESC;

--15
SELECT * FROM Customer
ORDER BY City,Age;

--16
SELECT * FROM Customer
ORDER BY LastName, FirstName;

--17
SELECT * FROM Customer
ORDER BY Email DESC;

--18
SELECT * FROM Customer
WHERE FirstName='A' OR FirstName='B' AND Age>25;

--19
SELECT * FROM Customer
WHERE NOT CITY='Austin' AND Email LIKE '%yahoo%';

--20
SELECT * FROM Customer
WHERE LastName LIKE 'M%' OR LastName LIKE '%n'
ORDER BY FirstName;
