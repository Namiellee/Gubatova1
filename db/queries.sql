SELECT n, t_s, sensor, value
FROM readings
ORDER BY n DESC, sensor
LIMIT 10;
SELECT sensor,
       MIN(value)   AS min_val,
       AVG(value)   AS avg_val,
       MAX(value)   AS max_val
FROM readings
GROUP BY sensor;
SELECT n, t_s, type, message
FROM events
ORDER BY n, id;