#ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

struct Sample0 {

	int			publicFoo;

	Sample0( void );
	~Sample0( void );

	void		publicBar0( void ) const;

};

class Sample {

public:

	int			publicFoo;

	Sample( void );
	~Sample( void );

	void		publicBar( void ) const;

};

#endif
