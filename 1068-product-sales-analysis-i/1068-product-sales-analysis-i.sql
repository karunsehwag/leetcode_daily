# Write your MySQL query statement below
SELECT Product.product_name,Sales.year,sales.price
From Product JOIN Sales ON Sales.product_id=Product.product_id;
