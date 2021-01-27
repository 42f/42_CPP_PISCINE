#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

class Sample {

public:

	int			publicFoo;

	Sample( void );
	~Sample( void );

	void		publicBar( void ) const;


private:

	int			_privateFoo;

	void		_privateBar( void ) const;

};

#endif
