CREATE DATABASE message_delete;
CREATE TABLE IF NOT EXISTS message_delete.messages(
    id INT(10) NOT NULL PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(200) NOT NULL
);
INSERT INTO message_delete.messages(name)
VALUES
('MESSAGE_ONE'),
('MESSAGE_TWO');
