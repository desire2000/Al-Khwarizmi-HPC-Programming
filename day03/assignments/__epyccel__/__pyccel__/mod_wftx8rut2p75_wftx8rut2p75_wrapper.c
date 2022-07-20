#define PY_ARRAY_UNIQUE_SYMBOL CWRAPPER_ARRAY_API
#include "numpy_version.h"
#include "numpy/arrayobject.h"
#include "cwrapper.h"
#include <stdlib.h>
#include <stdint.h>
#include "ndarrays.h"
#include "cwrapper_ndarrays.h"


void cavity_flow_numba(int64_t nit, int64_t nt, t_ndarray u, t_ndarray v, double dt, int64_t nx, int64_t ny, double dx, double dy, t_ndarray p, int64_t rho, double nu);

/*........................................*/


/*........................................*/

/*........................................*/
PyObject *cavity_flow_numba_wrapper(PyObject *self, PyObject *args, PyObject *kwargs)
{
    int64_t nit;
    int64_t nt;
    t_ndarray u = {.shape = NULL};
    t_ndarray v = {.shape = NULL};
    double dt;
    int64_t nx;
    int64_t ny;
    double dx;
    double dy;
    t_ndarray p = {.shape = NULL};
    int64_t rho;
    double nu;
    PyObject *nit_tmp;
    PyObject *nt_tmp;
    PyArrayObject *u_tmp;
    PyArrayObject *v_tmp;
    PyObject *dt_tmp;
    PyObject *nx_tmp;
    PyObject *ny_tmp;
    PyObject *dx_tmp;
    PyObject *dy_tmp;
    PyArrayObject *p_tmp;
    PyObject *rho_tmp;
    PyObject *nu_tmp;
    PyObject *result;
    static char *kwlist[] = {
        "nit",
        "nt",
        "u",
        "v",
        "dt",
        "nx",
        "ny",
        "dx",
        "dy",
        "p",
        "rho",
        "nu",
        NULL
    };
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "OOO!O!OOOOOO!OO", kwlist, &nit_tmp, &nt_tmp, &PyArray_Type, &u_tmp, &PyArray_Type, &v_tmp, &dt_tmp, &nx_tmp, &ny_tmp, &dx_tmp, &dy_tmp, &PyArray_Type, &p_tmp, &rho_tmp, &nu_tmp))
    {
        return NULL;
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
    if (PyIs_NativeInt(nt_tmp))
    {
        nt = PyInt64_to_Int64(nt_tmp);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "\"Argument must be native int\"");
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
    if (PyIs_NativeFloat(dt_tmp))
    {
        dt = PyDouble_to_Double(dt_tmp);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "\"Argument must be native float\"");
        return NULL;
    }
    if (PyIs_NativeInt(nx_tmp))
    {
        nx = PyInt64_to_Int64(nx_tmp);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "\"Argument must be native int\"");
        return NULL;
    }
    if (PyIs_NativeInt(ny_tmp))
    {
        ny = PyInt64_to_Int64(ny_tmp);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "\"Argument must be native int\"");
        return NULL;
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
    if (!pyarray_check(p_tmp, NPY_DOUBLE, 2, NO_ORDER_CHECK))
    {
        return NULL;
    }
    else
    {
        p = pyarray_to_ndarray(p_tmp);
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
    if (PyIs_NativeFloat(nu_tmp))
    {
        nu = PyDouble_to_Double(nu_tmp);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "\"Argument must be native float\"");
        return NULL;
    }
    cavity_flow_numba(nit, nt, u, v, dt, nx, ny, dx, dy, p, rho, nu);
    result = Py_BuildValue("");
    free_pointer(u);
    free_pointer(v);
    free_pointer(p);
    return result;
}
/*........................................*/

static int exec_func(PyObject* m)
{
    return 0;
}

/*........................................*/

static PyMethodDef mod_wftx8rut2p75_wftx8rut2p75_methods[] = {
    {
        "cavity_flow_numba",
        (PyCFunction)cavity_flow_numba_wrapper,
        METH_VARARGS | METH_KEYWORDS,
        ""
    },
    { NULL, NULL, 0, NULL}
};

/*........................................*/

static PyModuleDef_Slot mod_wftx8rut2p75_wftx8rut2p75_slots[] = {
    {Py_mod_exec, exec_func},
    {0, NULL},
};

/*........................................*/

static struct PyModuleDef mod_wftx8rut2p75_wftx8rut2p75_module = {
    PyModuleDef_HEAD_INIT,
    /* name of module */
    "mod_wftx8rut2p75_wftx8rut2p75",
    /* module documentation, may be NULL */
    NULL,
    /* size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
    0,
    mod_wftx8rut2p75_wftx8rut2p75_methods,
    mod_wftx8rut2p75_wftx8rut2p75_slots
};

/*........................................*/

PyMODINIT_FUNC PyInit_mod_wftx8rut2p75_wftx8rut2p75(void)
{
    import_array();
    return PyModuleDef_Init(&mod_wftx8rut2p75_wftx8rut2p75_module);
}
