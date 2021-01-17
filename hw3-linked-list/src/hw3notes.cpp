/*
// get the deleteme node to reach from
	//but don't actually touch it
	//so we can put previous before it.

	size_t i = 0;

	while(deleteMe->getLink()!=NULL && i<from-1){
		deleteMe = deleteMe->getLink();
		i++;
	}

	//insert previous before from node.
	//so we can delete that from node.

	Node* previous = NULL;

	while(deleteMe->getLink()!=NULL && (from-1)<i<(to-1)){
		previous = deleteMe;
		deleteMe = deleteMe->getLink();
		i++;
	}
	
	previous->setLink(deleteMe->getLink()->getLink());
	delete [] deleteMe;
	*/