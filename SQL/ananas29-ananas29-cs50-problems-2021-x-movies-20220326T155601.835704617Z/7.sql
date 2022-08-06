SELECT title, rating
FROM movies JOIN ratings
ON movies.id = ratings.movie_id  --matching "id" dlm table movies dan "movie_id" dlm table ratings
WHERE year = 2010
ORDER BY rating DESC, title ASC;