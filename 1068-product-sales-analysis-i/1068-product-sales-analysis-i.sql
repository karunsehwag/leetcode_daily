# Write your MySQL query statement below
SELECT Product.Product_name, Sales.year, Sales.price
FROM Sales, Product
WHERE Product.Product_id=Sales.product_id;