				********************************
The following function serves as an alternative to the ! operator, as it is not possible to properly overload it. cause a dummy node called "_nill" is used to represent the end of a node, which would typically be represented by a "null" value.

which mean in this case _(pointer) equal to  !(pointer)

bool _(pointer& x)
{
	return (x == _nill); //
}
				********************************