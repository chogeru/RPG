#pragma once
#include <vector>
#include "Task.h"

// �^�X�N�Ǘ��N���X
class TaskManager
{
private:
	// TaskManager�̃C���X�^���X
	static TaskManager* ms_instance;
	// �������ꂽ�^�X�N�̃��X�g
	std::vector<Task*> m_taskList;
	// ���X�g�ɒǉ�����^�X�N�̃��X�g
	std::vector<Task*> m_addList;
	// ���X�g�����菜���^�X�N�̃��X�g
	std::vector<Task*> m_removeList;
	// ���X�g����폜����^�X�N�̃��X�g
	std::vector<Task*> m_deleteList;

	// �ǉ�����^�X�N�𔽉f
	void AddTaskList();
	// ��菜���^�X�N�𔽉f
	void RemoveTaskList();
	// �폜����^�X�N�𔽉f
	void DeleteTaskList();

public:
	// �R���X�g���N�^
	TaskManager();
	// �f�X�g���N�^
	~TaskManager();

	// TaskManager�̃C���X�^���X���擾
	static TaskManager* Instance();
	// TaskManager�̃C���X�^���X��j��
	static void ClearInstance();

	// �^�X�N�����X�g�ɒǉ�
	void AddTask(Task* task);
	// �^�X�N�����X�g�����菜��
	void RemoveTask(Task* task);
	// �^�X�N���폜���ă��X�g�����菜��
	void DeleteTask(Task* task);

	// �X�V
	void Update();
	// �`��
	void Draw();
};
