grant all on *.* to 'andrian'@'%' identified by 'testpass';

grant select, insert, update, delete on udf.* to 'regonline'@'localhost' identified by 'online-pass';

flush privileges;

