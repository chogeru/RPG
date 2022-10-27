#include "TaskManager.h"

// TaskManager�̃C���X�^���X���`
TaskManager* TaskManager::ms_instance = nullptr;

// �R���X�g���N�^
TaskManager::TaskManager()
{
}

// �f�X�g���N�^
TaskManager::~TaskManager()
{
	// �^�X�N���X�g�ɓo�^����Ă���^�X�N��S�č폜
	for (int i = 0; i < m_taskList.size(); i++)
	{
		Task* task = m_taskList[i];
		delete task;
	}
	m_taskList.clear();
}

// TaskManager�̃C���X�^���X���擾
TaskManager* TaskManager::Instance()
{
	// �C���X�^���X����������Ă��Ȃ���ΐ���
	if (ms_instance == nullptr)
	{
		ms_instance = new TaskManager();
	}
	return ms_instance;
}

// TaskManager�̃C���X�^���X��j��
void TaskManager::ClearInstance()
{
	if (ms_instance == nullptr) return;
	delete ms_instance;
	ms_instance = nullptr;
}

// �^�X�N�����X�g�ɒǉ�
void TaskManager::AddTask(Task* task)
{
	m_addList.push_back(task);
}

// �ǉ�����^�X�N�𔽉f
void TaskManager::AddTaskList()
{
	for (int i = 0; i < m_addList.size(); i++)
	{
		// �ǉ�����^�X�N
		Task* addTask = m_addList[i];
		bool isAdd = false;

		// �ǉ�����^�X�N�̗D��x���݂ă��X�g�ɒǉ�
		auto begin = m_taskList.begin();
		auto end = m_taskList.end();
		for (auto it = begin; it != end; ++it)
		{
			// �ǉ�����^�X�N�̗D��x�̕����������ꍇ��
			// �����Ƀ^�X�N��ǉ�
			if (addTask->GetPriority() < (*it)->GetPriority())
			{
				m_taskList.insert(it, addTask);
				isAdd = true;
				break;
			}
		}
		if (!isAdd)
		{
			// �����ɗ����ꍇ�͗D��x����ԍ����̂�
			// ���X�g�̍Ō�ɒǉ�
			m_taskList.push_back(addTask);
		}
	}
	m_addList.clear();
}

// �^�X�N�����X�g����O��
void TaskManager::RemoveTask(Task* task)
{
	m_removeList.push_back(task);
}

// ��菜���^�X�N�𔽉f
void TaskManager::RemoveTaskList()
{
	for (int i = 0; i < m_removeList.size(); i++)
	{
		Task* removeTask = m_removeList[i];

		// ���X�g�������菜���^�X�N������
		auto begin = m_taskList.begin();
		auto end = m_taskList.end();
		auto find = std::find(begin, end, removeTask);
		// ������Ȃ���Ύ���
		if (find == m_taskList.end()) continue;

		// ������΃��X�g�����菜��
		m_taskList.erase(find);
	}
	m_removeList.clear();
}

// �^�X�N���폜���ă��X�g�����菜��
void TaskManager::DeleteTask(Task* task)
{
	m_deleteList.push_back(task);

	// �폜���X�g�ɒǉ����ꂽ�^�X�N��
	// �ǉ��^�X�N�̃��X�g�����菜��
	{
		auto begin = m_addList.begin();
		auto end = m_addList.end();
		auto find = std::find(begin, end, task);
		if (find != end) m_addList.erase(find);
	}
	// ��菜�����X�g�������菜��
	{
		auto begin = m_removeList.begin();
		auto end = m_removeList.end();
		auto find = std::find(begin, end, task);
		if (find != end) m_removeList.erase(find);
	}
}

// �폜����^�X�N�𔽉f
void TaskManager::DeleteTaskList()
{
	for (int i = 0; i < m_deleteList.size(); i++)
	{
		Task* deleteTask = m_deleteList[i];

		// ���X�g������폜����^�X�N������
		auto begin = m_taskList.begin();
		auto end = m_taskList.end();
		auto find = std::find(begin, end, deleteTask);
		// ������΃��X�g�����菜��
		if (find != m_taskList.end())
		{
			m_taskList.erase(find);
		}

		// �^�X�N���폜
		delete deleteTask;
	}
	m_deleteList.clear();
}

// �X�V
void TaskManager::Update()
{
	// �폜���郊�X�g��
	// �o�^����Ă���^�X�N���폜
	DeleteTaskList();
	// ��菜�����X�g��
	// �o�^����Ă���^�X�N�����X�g�����菜��
	RemoveTaskList();
	// �ǉ����X�g��
	// �o�^����Ă���^�X�N�����X�g�ɒǉ�
	AddTaskList();

	// ���X�g�ɓo�^����Ă���S�Ẵ^�X�N���X�V
	for (int i = 0; i < m_taskList.size(); i++)
	{
		m_taskList[i]->Update(CFPS::GetDeltaTime());
	}
}

// �`��
void TaskManager::Draw()
{
	// ���X�g�ɓo�^����Ă���S�Ẵ^�X�N��`��
	for (int i = 0; i < m_taskList.size(); i++)
	{
		m_taskList[i]->Draw();
	}
}