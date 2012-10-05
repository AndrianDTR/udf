grant all on *.* to 'andrian'@'127.0.0.1' identified by 'testpass';

grant select, insert, update, delete on udf.* to 'regonline'@'localhost' identified by 'online-pass';

flush privileges;

