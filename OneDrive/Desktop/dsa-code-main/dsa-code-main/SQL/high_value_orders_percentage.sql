-- Find the percentage of orders with a total amount greater than 1000

SELECT 
  ROUND(
    (COUNT(CASE WHEN TotalAmount > 1000 THEN 1 END) * 100.0 /
     COUNT(*)), 2
  ) AS HighValueOrderPercentage
FROM Orders;
