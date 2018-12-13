#include "stdafx.h"
#include <stdexcept>
#include "CppUnitTest.h"
#include "../Laba3_3(alg)/Tree.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(isEmpty_not)
		{
			Tree A;
			A.insert(3);
			A.insert(2);
			A.insert(1);
			A.insert(7);
			Assert::IsFalse(A.isEmpty(A.root));
        }
		TEST_METHOD(Dcreate_iterator_ok)
		{
			int B[4];
			B[0] = 5;
			B[1] = 3;
			B[2] = 1;
			B[3] = 2;
			Tree A;
			A.insert(3);
			A.insert(5);
			A.insert(2);
			A.insert(1);
			int exit = 1;
			int i = 0;
			Iterator* diterator = A.Dcreate_iterator();
			while (diterator->has_next())

			{
				if (diterator->next() != B[i])
					exit = 0;
				i++;
			}
			Assert::IsTrue(exit == 1);
		}
        TEST_METHOD(Remove_not_empty)
		{
			Tree A;
			
			char error;
			try
			{
				A.remove(1);
			}
			catch (const std::out_of_range& error)
			{

				Assert::AreEqual("Tree is empty", error.what());
			}

			
			
		}
		TEST_METHOD(Remove_first_elem)
		{
			int B[4];
			B[0] = 5;
			B[1] = 3;
			B[2] = 1;
			B[3] = 2;
			
			Tree A;
			A.insert(3);
			A.insert(5);
			A.insert(2);
			A.insert(1);
			A.insert(7);
		
			A.remove(7);
			
			int exit = 1;
			int i = 0;
			Iterator* diterator = A.Dcreate_iterator();
			while (diterator->has_next())

			{
				if (diterator->next() != B[i])
					exit = 0;
				i++;
			}
			Assert::IsTrue(exit == 1);
		}
		TEST_METHOD(Remove_last_elem)
		{
			int B[4];
			B[0] = 7;
			B[1] = 5;
			B[2] = 3;
			B[3] = 2;
			

			Tree A;
			A.insert(3);
			A.insert(5);
			A.insert(2);
			A.insert(1);
			A.insert(7);

			A.remove(1);
			
			int exit = 1;
			int i = 0;
			Iterator* diterator = A.Dcreate_iterator();
			while (diterator->has_next())

			{
				if (diterator->next() != B[i])
					exit = 0;
				i++;
			}
			Assert::IsTrue(exit == 1);
		}
		TEST_METHOD(Remove_middle_elem)
		{
			int B[4];
			B[0] = 7;
			B[1] = 3;
			B[2] = 1;
			B[3] = 2;


			Tree A;
			A.insert(3);
			A.insert(5);
			A.insert(2);
			A.insert(1);
			A.insert(7);

			A.remove(5);
			
			int exit = 1;
			int i = 0;
			Iterator* diterator = A.Dcreate_iterator();
			while (diterator->has_next())

			{
				if (diterator->next() != B[i])
					exit = 0;
				i++;
			}
			Assert::IsTrue(exit == 1);
		}
		TEST_METHOD(Insert_first_ok)
		{
			int B=4;
			Tree A;
			A.insert(4);
			int exit = 1;
			Iterator* diterator = A.Dcreate_iterator();
			
				if (diterator->next() != B)
					exit = 0;
			
				
			
			Assert::IsTrue(exit==1);
		}
		TEST_METHOD(Sort_and_Insert_middle_and_last_ok)
		{
			//сортировка происходит в функции вставки.
			/*Поэтому мы одновременно проверяем присоединился
				элемент ли к дереву и какую позицию занял*/
			int B[4];
			B[0] = 7;
			B[1] = 2;
			B[2] = 1;
			B[3] = 3;
			Tree A;
			A.insert(4);
			A.insert(1);
			A.insert(3);
			A.insert(2);
			
			int exit = 1;
			int i = 1;
			
			//проверка со 2-го уровня,голову не рассматриваем
			Iterator* diterator = A.Dcreate_iterator();
			if (diterator->has_next()) diterator->next();
			while (diterator->has_next())

			{
				if (diterator->next() != B[i])
					exit = 0;
				i++;
			}
			Assert::IsTrue(exit == 1);
		}
        TEST_METHOD(Size_after_remove)
		{
			Tree A;
			A.insert(3);
			A.insert(2);
			A.insert(1);
			A.insert(7);
			A.remove(7);
			
			Assert::IsTrue(A.size==3);
		}
		TEST_METHOD(Size_of_tree)
		{
			Tree A;
			A.insert(3);
			A.insert(2);
			A.insert(1);
			A.insert(7);
            Assert::IsTrue(A.size == 4);
		}
		TEST_METHOD(Search_last_elem)
		{
			Tree A;
			A.insert(3);
			A.insert(2);
			A.insert(1);
			A.insert(7);
			Assert::IsTrue(A.Search(2));
		}
		TEST_METHOD(Search_first_elem)
		{
			Tree A;
			A.insert(3);
			A.insert(2);
			A.insert(1);
			A.insert(7);
			Assert::IsTrue(A.Search(7));
		}
		TEST_METHOD(Search_middle_elem)
		{
			Tree A;
			A.insert(3);
			A.insert(2);
			A.insert(1);
			A.insert(4);
			A.insert(6);
			A.insert(9);
			A.insert(7);
			Assert::IsTrue(A.Search(6));
		}
		TEST_METHOD(Dcreate_iterator_bad)
		{
			int B[4];
			B[0] = 5;
			B[1] = 3;
			B[2] = 8;
			B[3] = 2;
			Tree A;
			A.insert(3);
			A.insert(5);
			A.insert(2);
			A.insert(1);
			int exit = 1;
			int i = 0;
			Iterator* diterator = A.Dcreate_iterator();
			while (diterator->has_next())

			{
				if (diterator->next() != B[i])
					exit = 0;
				i++;
			}
			Assert::IsTrue(exit == 0);
		}
		TEST_METHOD(Bcreate_iterator_bad)
		{
			int B[4];
			B[0] = 5;
			B[1] = 3;
			B[2] = 8;
			B[3] = 2;
			Tree A;
			A.insert(3);
			A.insert(5);
			A.insert(2);
			A.insert(1);
			int exit = 1;
			int i = 0;
			Iterator* biterator = A.Bcreate_iterator();
			while (biterator->has_next())

			{
				if (biterator->next() != B[i])
					exit = 0;
				i++;
			}
			Assert::IsTrue(exit == 0);
		}
		TEST_METHOD(Bcreate_iterator_ok)
		{
			int B[4];
			B[0] = 4;
			B[1] = 3;
			B[2] = 2;
			B[3] = 1;
			Tree A;
			A.insert(3);
			A.insert(4);
			A.insert(2);
			A.insert(1);
			int exit = 1;
			int i = 0;
			Iterator* biterator = A.Bcreate_iterator();
			while (biterator->has_next())

			{
				if (biterator->next() != B[i])
					exit = 0;
				i++;
			}

			Assert::IsTrue(exit == 1);
		}
		
