#define PY_ARRAY_UNIQUE_SYMBOL CWRAPPER_ARRAY_API
#include "numpy_version.h"
#include "numpy/arrayobject.h"
#include "cwrapper.h"
#include <stdlib.h>
#include "ndarrays.h"
#include <stdint.h>
#include "cwrapper_ndarrays.h"


void build_up_b_pyccel(t_ndarray p, t_ndarray b, int64_t rho, double dt, t_ndarray u, t_ndarray v, double dx, double dy);

/*........................................*/


/*........................................*/

/*........................................*/
PyObject *build_up_b_pyccel_wrapper(PyObject *self, PyObject *args, PyObject *kwargs)
{
    t_ndarray p = {.shape = NULL};
    t_ndarray b = {.shape = NULL};
    int64_t rho;
    double dt;
    t_ndarray u = {.shape = NULL};
    t_ndarray v = {.shape = NULL};
    double dx;
    double dy;
    PyArrayObject *p_tmp;
    PyArrayObject *b_tmp;
    PyObject *rho_tmp;
    PyObject *dt_tmp;
    PyArrayObject *u_tmp;
    PyArrayObject *v_tmp;
    PyObject *dx_tmp;
    PyObject *dy_tmp;
    PyObject *result;
    static char *kwlist[] = {
        "p",
        "b",
        "rho",
        "dt",
        "u",
        "v",
        "dx",
        "dy",
        NULL
    };
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O!O!OOO!O!OO", kwlist, &PyArray_Type, &p_tmp, &PyArray_Type, &b_tmp, &rho_tmp, &dt_tmp, &PyArray_Type, &u_tmp, &PyArray_Type, &v_tmp, &dx_tmp, &dy_tmp))
    {
        return NULL;
    }
    if (!pyarray_check(p_tmp, NPY_DOUBLE, 2, NO_ORDER_CHECK))
    {
        return NULL;
    }
    else
    {
        p = pyarray_to_ndarray(p_tmp);
    }
    if (!pyarray_check(b_tmp, NPY_DOUBLE, 2, NO_ORDER_CHECK))
    {
        return NULL;
    }
    else
    {
        b = pyarray_to_ndarray(b_tmp);
    }
    if (PyIs_NativeInt(rho_tmp))
    {
        rho = PyInt64_to_Int64(rho_tmp);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "\"Argument must be native int\"");
        return NULL;
    }
    if (PyIs_NativeFloat(dt_tmp))
    {
        dt = PyDouble_to_Double(dt_tmp);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "\"Argument must be native float\"");
        return NULL;
    }
    if (!pyarray_check(u_tmp, NPY_DOUBLE, 2, NO_ORDER_CHECK))
    {
        return NULL;
    }
    else
    {
        u = pyarray_to_ndarray(u_tmp);
    }
    if (!pyarray_check(v_tmp, NPY_DOUBLE, 2, NO_ORDER_CHECK))
    {
        return NULL;
    }
    else
    {
        v = pyarray_to_ndarray(v_tmp);
    }
    if (PyIs_NativeFloat(dx_tmp))
    {
        dx = PyDouble_to_Double(dx_tmp);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "\"Argument must be native float\"");
        return NULL;
    }
    if (PyIs_NativeFloat(dy_tmp))
    {
        dy = PyDouble_to_Double(dy_tmp);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "\"Argument must be native float\"");
        return NULL;
    }
    build_up_b_pyccel(p, b, rho, dt, u, v, dx, dy);
    result = Py_BuildValue("");
    free_pointer(p);
    free_pointer(b);
    free_pointer(u);
    free_pointer(v);
    return result;
}
/*........................................*/

static int exec_func(PyObject* m)
{
    return 0;
}

/*........................................*/

static PyMethodDef mod_sert5bxtdnh9_sert5bxtdnh9_methods[] = {
    {
        "build_up_b_pyccel",
        (PyCFunction)build_up_b_pyccel_wrapper,
        METH_VARARGS | METH_KEYWORDS,
        ""
    },
    { NULL, NULL, 0, NULL}
};

/*........................................*/

static PyModuleDef_Slot mod_sert5bxtdnh9_sert5bxtdnh9_slots[] = {
    {Py_mod_exec, exec_func},
    {0, NULL},
};

/*........................................*/

static struct PyModuleDef mod_sert5bxtdnh9_sert5bxtdnh9_module = {
    PyModuleDef_HEAD_INIT,
    /* name of module */
    "mod_sert5bxtdnh9_sert5bxtdnh9",
    /* module documentation, may be NULL */
    NULL,
    /* size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
    0,
    mod_sert5bxtdnh9_sert5bxtdnh9_methods,
    mod_sert5bxtdnh9_sert5bxtdnh9_slots
};

/*........................................*/

PyMODINIT_FUNC PyInit_mod_sert5bxtdnh9_sert5bxtdnh9(void)
{
    import_array();
    return PyModuleDef_Init(&mod_sert5bxtdnh9_sert5bxtdnh9_module);
}
