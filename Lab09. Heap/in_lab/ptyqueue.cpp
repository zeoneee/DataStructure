// 2019112587 ������

#include "ptyqueue.h"

template <class DT>
PtyQueue<DT>::PtyQueue<DT>(int maxNumber) {
	Heap<DT>::Heap(maxNumber);
}

template<class DT>
void PtyQueue<DT>::enqueue(const DT& newDataItem)
{
	Heap<DT>::insert(newDataItem);
}

template<class DT>
DT PtyQueue<DT>::dequeue()
{
	DT data = Heap<DT>::removeMax();
	return data;
}
