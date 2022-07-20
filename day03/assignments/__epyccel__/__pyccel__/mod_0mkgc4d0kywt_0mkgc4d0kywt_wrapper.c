#define PY_ARRAY_UNIQUE_SYMBOL CWRAPPER_ARRAY_API
#include "numpy_version.h"
#include "numpy/arrayobject.h"
#include "cwrapper.h"
#include <stdlib.h>
#include "ndarrays.h"
#include <stdint.h>
#include "cwrapper_ndarrays.h"


void pressure_poisson_pyccel(t_ndarray p, t_ndarray pn, double dx, double dy, t_ndarray b, int64_t nit);

/*........................................*/


/*........................................*/

/*........................................*/
PyObject *pressure_poisson_pyccel_wrapper(PyObject *self, PyObject *args, PyObject *kwargs)
{
    t_ndarray p = {.shape = NULL};
    t_ndarray pn = {.shape = NULL};
    double dx;
    double dy;
    t_ndarray b = {.shape = NULL};
    int64_t nit;
    PyArrayObject *p_tmp;
    PyArrayObject *pn_tmp;
    PyObject *dx_tmp;
    PyObject *dy_tmp;
    PyArrayObject *b_tmp;
    PyObject *nit_tmp;
    PyObject *result;
    static char *kwlist[] = {
        "p",
        "pn",
        "dx",
        "dy",
        "b",
        "nit",
        NULL
    };
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O!O!OOO!O", kwlist, &PyArray_Type, &p_tmp, &PyArray_Type, &pn_tmp, &dx_tmp, &dy_tmp, &PyArray_Type, &b_tmp, &nit_tmp))
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
    if (!pyarray_check(pn_tmp, NPY_DOUBLE, 2, NO_ORDER_CHECK))
    {
        return NULL;
    }
    else
    {
        pn = pyarray_to_ndarray(pn_tmp);
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
    if (!pyarray_check(b_tmp, NPY_DOUBLE, 2, NO_ORDER_CHECK))
    {
        return NULL;
    }
    else
    {
        b = pyarray_to_ndarray(b_tmp);
    }
    if (PyIs_NativeInt(nit_tmp))
    {
        nit = PyInt64_to_Int64(nit_tmp);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "\"Argument must be native int\"");
        return NULL;
    }
    pressure_poisson_pyccel(p, pn, dx, dy, b, nit);
    result = Py_BuildValue("");
    free_pointer(p);
    free_pointer(pn);
    free_pointer(b);
    return result;
}
/*........................................*/

static int exec_func(PyObject* m)
{
    return 0;
}

/*........................................*/

static PyMethodDef mod_0mkgc4d0kywt_0mkgc4d0kywt_methods[] = {
    {
        "pressure_poisson_pyccel",
        (PyCFunction)pressure_poisson_pyccel_wrapper,
        METH_VARARGS | METH_KEYWORDS,
        ""
    },
    { NULL, NULL, 0, NULL}
};

/*........................................*/

static PyModuleDef_Slot mod_0mkgc4d0kywt_0mkgc4d0kywt_slots[] = {
    {Py_mod_exec, exec_func},
    {0, NULL},
};

/*........................................*/

static struct PyModuleDef mod_0mkgc4d0kywt_0mkgc4d0kywt_module = {
    PyModuleDef_HEAD_INIT,
    /* name of module */
    "mod_0mkgc4d0kywt_0mkgc4d0kywt",
    /* module documentation, may be NULL */
    NULL,
    /* size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
    0,
    mod_0mkgc4d0kywt_0mkgc4d0kywt_methods,
    mod_0mkgc4d0kywt_0mkgc4d0kywt_slots
};

/*........................................*/

PyMODINIT_FUNC PyInit_mod_0mkgc4d0kywt_0mkgc4d0kywt(void)
{
    import_array();
    return PyModuleDef_Init(&mod_0mkgc4d0kywt_0mkgc4d0kywt_module);
}
