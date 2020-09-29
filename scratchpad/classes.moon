gettype = (o) ->
	t = type o
	if t == 'table'
		m = getmetatable o
		return m.__class if m.__class
	t

gettypename = (o) ->
	t = type o
	if t == 'table'
		m = getmetatable o
		c = m.__class
		return c.__name if c and c.__name
	t

sametype = (a, b) ->
	(gettype a) == (gettype b)

{
	type: gettype, typename: gettypename, :sametype
}
