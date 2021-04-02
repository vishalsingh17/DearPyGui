#include "mvTypeBases.h"
#include <utility>
#include "mvApp.h"
#include "mvUtilities.h"
#include "mvAppLog.h"
#include "mvItemRegistry.h"

namespace Marvel {

	mvIntPtrBase::mvIntPtrBase(const std::string& name, int default_value)
		: 
		mvAppItem(name)
	{
		m_value = std::make_shared<int>(default_value);
	}

	void mvIntPtrBase::setDataSource(const std::string& dataSource)
	{
		if (dataSource == m_source) return;
		m_source = dataSource;

		mvRef<mvAppItem> item = mvApp::GetApp()->getItemRegistry().getItem(dataSource);
		if (!item)
		{
			ThrowPythonException("Source item not found.");
			return;
		}
		if (item->getValueType() != getValueType())
		{
			ThrowPythonException("Values types do not match");
			return;
		}
		m_value = std::get<std::shared_ptr<int>>(item->getValue());
	}

	PyObject* mvIntPtrBase::getPyValue()
	{
		return ToPyInt(*m_value);
	}

	void mvIntPtrBase::setPyValue(PyObject* value)
	{
		*m_value = ToInt(value);
	}

	mvInt4PtrBase::mvInt4PtrBase(const std::string& name, int* default_value)
		: mvAppItem(name)
	{
		m_value = std::make_shared<std::array<int, 4>>(std::array{ default_value[0], 
			default_value[1], default_value[2], default_value[3] });
	}

	PyObject* mvInt4PtrBase::getPyValue()
	{
		return ToPyIntList(m_value->data(), 4);
	}

	void mvInt4PtrBase::setPyValue(PyObject* value)
	{
		std::vector<int> temp = ToIntVect(value);
		std::array<int, 4> temp_array;
		for (int i = 0; i < temp_array.size(); i++)
			temp_array[i] = temp[i];
		*m_value = temp_array;
	}

	void mvInt4PtrBase::setDataSource(const std::string& dataSource)
	{
		if (dataSource == m_source) return;
		m_source = dataSource;

		mvRef<mvAppItem> item = mvApp::GetApp()->getItemRegistry().getItem(dataSource);
		if (!item)
		{
			ThrowPythonException("Source item not found.");
			return;
		}
		if (item->getValueType() != getValueType())
		{
			ThrowPythonException("Values types do not match");
			return;
		}
		m_value = std::get<std::shared_ptr<std::array<int, 4>>>(item->getValue());
	}

	mvFloatPtrBase::mvFloatPtrBase(const std::string& name, float default_value)
		: mvAppItem(name)
	{
		m_value = std::make_shared<float>(default_value);
	}

	PyObject* mvFloatPtrBase::getPyValue()
	{
		return ToPyFloat(*m_value);
	}

	void mvFloatPtrBase::setPyValue(PyObject* value)
	{
		*m_value = ToFloat(value);
	}

	void mvFloatPtrBase::setDataSource(const std::string& dataSource)
	{
		if (dataSource == m_source) return;
		m_source = dataSource;

		mvRef<mvAppItem> item = mvApp::GetApp()->getItemRegistry().getItem(dataSource);
		if (!item)
		{
			ThrowPythonException("Source item not found.");
			return;
		}
		if (item->getValueType() != getValueType())
		{
			ThrowPythonException("Values types do not match");
			return;
		}
		m_value = std::get<std::shared_ptr<float>>(item->getValue());
	}

	mvFloat4PtrBase::mvFloat4PtrBase(const std::string& name, float* default_value)
		: mvAppItem(name)
	{
		m_value = std::make_shared<std::array<float, 4>>(std::array{ default_value[0], default_value[1], default_value[2], default_value[3] });
	}

	PyObject* mvFloat4PtrBase::getPyValue()
	{
		return ToPyFloatList(m_value->data(), 4);
	}

	void mvFloat4PtrBase::setPyValue(PyObject* value)
	{
		std::vector<float> temp = ToFloatVect(value);
		std::array<float, 4> temp_array;
		for (int i = 0; i < temp_array.size(); i++)
			temp_array[i] = temp[i];
		*m_value = temp_array;
	}

	void mvFloat4PtrBase::setDataSource(const std::string& dataSource)
	{
		if (dataSource == m_source) return;
		m_source = dataSource;

		mvRef<mvAppItem> item = mvApp::GetApp()->getItemRegistry().getItem(dataSource);
		if (!item)
		{
			ThrowPythonException("Source item not found.");
			return;
		}
		if (item->getValueType() != getValueType())
		{
			ThrowPythonException("Values types do not match");
			return;
		}
		m_value = std::get<std::shared_ptr<std::array<float, 4>>>(item->getValue());
	}

	mvColorPtrBase::mvColorPtrBase(const std::string& name, const float* default_value)
		: mvAppItem(name)
	{
		m_value = std::make_shared<std::array<float, 4>>(std::array{ default_value[0], default_value[1], default_value[2], default_value[3] });
	}

	PyObject* mvColorPtrBase::getPyValue()
	{
		mvColor color = { 
			m_value->data()[0], 
			m_value->data()[1], 
			m_value->data()[2], 
			m_value->data()[3]
		};
		return ToPyColor(color);
	}

	void mvColorPtrBase::setPyValue(PyObject* value)
	{
		std::vector<float> temp = ToFloatVect(value);
		std::array<float, 4> temp_array;
		for (int i = 0; i < temp_array.size(); i++)
			temp_array[i] = temp[i];
		*m_value = temp_array;
	}

	void mvColorPtrBase::setDataSource(const std::string& dataSource)
	{
		if (dataSource == m_source) return;
		m_source = dataSource;

		mvRef<mvAppItem> item = mvApp::GetApp()->getItemRegistry().getItem(dataSource);
		if (!item)
		{
			ThrowPythonException("Source item not found.");
			return;
		}
		if (item->getValueType() != getValueType())
		{
			ThrowPythonException("Values types do not match");
			return;
		}
		m_value = std::get<std::shared_ptr<std::array<float, 4>>>(item->getValue());
	}

	mvBoolPtrBase::mvBoolPtrBase(const std::string& name, bool default_value)
		: mvAppItem(name)
	{
		m_value = std::make_shared<bool>(default_value);
	}

	PyObject* mvBoolPtrBase::getPyValue()
	{
		return ToPyBool(*m_value);
	}

	void mvBoolPtrBase::setPyValue(PyObject* value)
	{
		*m_value = ToBool(value);
	}

	void mvBoolPtrBase::setDataSource(const std::string& dataSource)
	{
		if (dataSource == m_source) return;
		m_source = dataSource;

		mvRef<mvAppItem> item = mvApp::GetApp()->getItemRegistry().getItem(dataSource);
		if (!item)
		{
			ThrowPythonException("Source item not found.");
			return;
		}
		if (item->getValueType() != getValueType())
		{
			ThrowPythonException("Values types do not match");
			return;
		}
		m_value = std::get<std::shared_ptr<bool>>(item->getValue());
	}

	mvStringPtrBase::mvStringPtrBase(const std::string& name, const std::string& default_value)
		: mvAppItem(name)
	{
		m_value = std::make_shared<std::string>(default_value);
	}

	PyObject* mvStringPtrBase::getPyValue()
	{
		return ToPyString(*m_value);
	}

	void mvStringPtrBase::setPyValue(PyObject* value)
	{
		*m_value = ToString(value);
	}

	void mvStringPtrBase::setDataSource(const std::string& dataSource)
	{
		if (dataSource == m_source) return;
		m_source = dataSource;

		mvRef<mvAppItem> item = mvApp::GetApp()->getItemRegistry().getItem(dataSource);
		if (!item)
		{
			ThrowPythonException("Source item not found.");
			return;
		}
		if (item->getValueType() != getValueType())
		{
			ThrowPythonException("Values types do not match");
			return;
		}
		m_value = std::get<std::shared_ptr<std::string>>(item->getValue());
	}

	mvTimePtrBase::mvTimePtrBase(const std::string& name, const tm& default_value)
		: mvAppItem(name)
	{

		m_value = std::make_shared<tm>(default_value);
		m_imvalue = std::make_shared<ImPlotTime>(ImPlot::MkGmtTime(m_value.get()));
	}

	PyObject* mvTimePtrBase::getPyValue()
	{
		return ToPyTime(*m_value);
	}

	void mvTimePtrBase::setPyValue(PyObject* value)
	{
		*m_value = ToTime(value);
		ImPlot::GetGmtTime(*m_imvalue, m_value.get());
	}

	mvFloatVectPtrBase::mvFloatVectPtrBase(const std::string& name, const std::vector<float>& default_value)
		: mvAppItem(name)
	{
		m_value = std::make_shared<std::vector<float>>(default_value);
	}

	PyObject* mvFloatVectPtrBase::getPyValue()
	{
		return ToPyList(*m_value);
	}

	void mvFloatVectPtrBase::setPyValue(PyObject* value)
	{
		*m_value = ToFloatVect(value);
	}

	void mvFloatVectPtrBase::setDataSource(const std::string& dataSource)
	{
		if (dataSource == m_source) return;
		m_source = dataSource;

		mvRef<mvAppItem> item = mvApp::GetApp()->getItemRegistry().getItem(dataSource);
		if (!item)
		{
			ThrowPythonException("Source item not found.");
			return;
		}
		if (item->getValueType() != getValueType())
		{
			ThrowPythonException("Values types do not match");
			return;
		}
		m_value = std::get<std::shared_ptr<std::vector<float>>>(item->getValue());
	}

	mvBaseWindowAppitem::mvBaseWindowAppitem(const std::string& name)
		: 
		mvAppItem(name)
	{
	}

	void mvBaseWindowAppitem::addFlag(ImGuiWindowFlags flag) 
	{ 
		m_windowflags |= flag; 
	}

	void mvBaseWindowAppitem::removeFlag(ImGuiWindowFlags flag) 
	{ 
		m_windowflags &= ~flag; 
	}

	void mvBaseWindowAppitem::setWindowPos(float x, float y)
	{
		m_xpos = (int)x;
		m_ypos = (int)y;
		m_dirty_pos = true;
	}

	void mvBaseWindowAppitem::setWidth(int width)
	{ 
		m_width = width;
		m_dirty_size = true; 
	}

	void mvBaseWindowAppitem::setHeight(int height)
	{
		m_height = height;
		m_dirty_size = true; 
	}

	mvVec2 mvBaseWindowAppitem::getWindowPos() const
	{
		return { (float)m_xpos, (float)m_ypos };
	}

	bool mvBaseWindowAppitem::prerender()
	{

		if (!m_show)
			return false;

		if (m_dirty_size)
		{
			ImGui::SetNextWindowSize(ImVec2((float)m_width, (float)m_height));
			m_dirty_size = false;
		}

		if (m_dirty_pos)
		{
			ImGui::SetNextWindowPos(ImVec2((float)m_xpos, (float)m_ypos));
			m_dirty_pos = false;
		}

		if (!ImGui::Begin(m_label.c_str(), &m_show, m_windowflags))
		{
			ImGui::End();
			return false;
		}

		return true;
	}

	void mvBaseWindowAppitem::setExtraConfigDict(PyObject* dict)
	{
		if (dict == nullptr)
			return;
		 
		if (PyObject* item = PyDict_GetItemString(dict, "x_pos")) setWindowPos((float)ToInt(item), (float)m_ypos);
		if (PyObject* item = PyDict_GetItemString(dict, "y_pos")) setWindowPos((float)m_xpos, (float)ToInt(item));

		// helper for bit flipping
		auto flagop = [dict](const char* keyword, int flag, int& flags)
		{
			if (PyObject* item = PyDict_GetItemString(dict, keyword)) ToBool(item) ? flags |= flag : flags &= ~flag;
		};

		// window flags
		flagop("autosize", ImGuiWindowFlags_AlwaysAutoResize, m_windowflags);
		flagop("no_move", ImGuiWindowFlags_NoMove, m_windowflags);
		flagop("no_resize", ImGuiWindowFlags_NoResize, m_windowflags);
		flagop("no_title_bar", ImGuiWindowFlags_NoTitleBar, m_windowflags);
		flagop("no_scrollbar", ImGuiWindowFlags_NoScrollbar, m_windowflags);
		flagop("no_collapse", ImGuiWindowFlags_NoCollapse, m_windowflags);
		flagop("horizontal_scrollbar", ImGuiWindowFlags_HorizontalScrollbar, m_windowflags);
		flagop("no_focus_on_appearing", ImGuiWindowFlags_NoFocusOnAppearing, m_windowflags);
		flagop("no_bring_to_front_on_focus", ImGuiWindowFlags_NoBringToFrontOnFocus, m_windowflags);
		flagop("menubar", ImGuiWindowFlags_MenuBar, m_windowflags);
		flagop("no_background", ImGuiWindowFlags_NoBackground, m_windowflags);

	}

	void mvBaseWindowAppitem::getExtraConfigDict(PyObject* dict)
	{
		if (dict == nullptr)
			return;
		 
		PyDict_SetItemString(dict, "x_pos", ToPyInt(m_xpos));
		PyDict_SetItemString(dict, "y_pos", ToPyInt(m_ypos));

		// helper to check and set bit
		auto checkbitset = [dict](const char* keyword, int flag, const int& flags)
		{
			PyDict_SetItemString(dict, keyword, ToPyBool(flags & flag));
		};

		// window flags
		checkbitset("autosize", ImGuiWindowFlags_AlwaysAutoResize, m_windowflags);
		checkbitset("no_resize", ImGuiWindowFlags_NoResize, m_windowflags);
		checkbitset("no_title_bar", ImGuiWindowFlags_NoTitleBar, m_windowflags);
		checkbitset("no_move", ImGuiWindowFlags_NoMove, m_windowflags);
		checkbitset("no_scrollbar", ImGuiWindowFlags_NoScrollbar, m_windowflags);
		checkbitset("no_collapse", ImGuiWindowFlags_NoCollapse, m_windowflags);
		checkbitset("horizontal_scrollbar", ImGuiWindowFlags_HorizontalScrollbar, m_windowflags);
		checkbitset("no_focus_on_appearing", ImGuiWindowFlags_NoFocusOnAppearing, m_windowflags);
		checkbitset("no_bring_to_front_on_focus", ImGuiWindowFlags_NoBringToFrontOnFocus, m_windowflags);
		checkbitset("menubar", ImGuiWindowFlags_MenuBar, m_windowflags);
		checkbitset("no_background", ImGuiWindowFlags_NoBackground, m_windowflags);
	}

}