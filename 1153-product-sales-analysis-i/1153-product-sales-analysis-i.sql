# Write your MySQL query statement below
SELECT product_name,year,price
FROM Sales
LEFT JOIN Product
ON sales.product_id = Product.product_id;
