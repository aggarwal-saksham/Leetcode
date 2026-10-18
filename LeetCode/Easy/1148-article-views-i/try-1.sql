/*
 * Problem #1148: Article Views I
 * Difficulty: Easy
 * Submission: Try 1
 * status: Accepted
 * Language: mysql
 * Date: 10/17/2026, 7:33:05 PM
 * Link: https://leetcode.com/problems/article-views-i/
 */

# Write your MySQL query statement below
SELECT DISTINCT author_id AS id FROM Views
WHERE author_id = viewer_id
ORDER BY author_id;
