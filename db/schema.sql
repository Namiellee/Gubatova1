CREATE TABLE IF NOT EXISTS readings(
    id      INTEGER PRIMARY KEY AUTOINCREMENT,
    n       INTEGER NOT NULL,
    t_s     REAL    NOT NULL,
    sensor  TEXT    NOT NULL,
    value   REAL    NOT NULL
);
CREATE TABLE IF NOT EXISTS events(
    id      INTEGER PRIMARY KEY AUTOINCREMENT,
    n       INTEGER NOT NULL,
    t_s     REAL    NOT NULL,
    type    TEXT    NOT NULL,
    message TEXT
);
CREATE INDEX IF NOT EXISTS idx_readings_n ON readings(n);
CREATE INDEX IF NOT EXISTS idx_events_n   ON events(n);