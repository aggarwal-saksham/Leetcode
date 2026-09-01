/*
 * Problem #595: Big Countries
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: mysql
 * Date: 8/22/2026, 2:04:12 AM
 * Link: https://leetcode.com/problems/big-countries/
 */

# Write your MySQL query statement below
SELECT name, population, area 
FROM World 
WHERE area >= 3000000 OR population >= 25000000;
