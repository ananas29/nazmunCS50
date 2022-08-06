SELECT AVG(rating) FROM ratings JOIN movies ON movies.id = ratings.movie_id --(id dlm table movies & movie_id dlm table ratings)
WHERE year = 2012;

--istilah JOIN untuk menggabungkan table dan mencari nilai yg sama untuk disesuaikan yaitu kolom id dan movie_id